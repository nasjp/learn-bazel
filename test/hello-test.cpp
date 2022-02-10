#define BOOST_TEST_MODULE hello

#include <jdbc/cppconn/driver.h>
#include <jdbc/cppconn/exception.h>
#include <jdbc/cppconn/prepared_statement.h>

#include <boost/test/unit_test.hpp>
#include <iostream>

#include "main/hello-greet.h"

BOOST_AUTO_TEST_CASE(test_boost) { BOOST_TEST(true); }

BOOST_AUTO_TEST_CASE(test_get_greet) {
  BOOST_TEST(get_greet("Bazel") == "Hello Bazel");
}

auto test_create = [](sql::Connection *conn) {
  auto stmt = conn->createStatement();
  stmt->execute("DROP TABLE IF EXISTS inventory");
  BOOST_LOG_TRIVIAL(debug) << "Finished dropping table (if existed)";

  stmt->execute(
      "CREATE TABLE inventory ("
      "id serial PRIMARY KEY,"
      "name VARCHAR(50),"
      "quantity INTEGER"
      ");");
  BOOST_LOG_TRIVIAL(debug) << "Finished creating table";

  auto pstmt = conn->prepareStatement(
      "INSERT INTO inventory(name, quantity) VALUES(?,?)");
  pstmt->setString(1, "banana");
  pstmt->setInt(2, 150);
  pstmt->execute();
  BOOST_LOG_TRIVIAL(debug) << "One row inserted.";

  pstmt->setString(1, "orange");
  pstmt->setInt(2, 154);
  pstmt->execute();
  BOOST_LOG_TRIVIAL(debug) << "One row inserted.";

  pstmt->setString(1, "apple");
  pstmt->setInt(2, 100);
  pstmt->execute();
  BOOST_LOG_TRIVIAL(debug) << "One row inserted.";

  delete stmt;
  delete pstmt;
};

auto test_read = [](sql::Connection *conn) {
  auto pstmt = conn->prepareStatement("SELECT * FROM inventory;");
  auto result = pstmt->executeQuery();

  while (result->next())
    BOOST_LOG_TRIVIAL(debug)
        << "Reading from table (" << result->getInt(1) << ", "
        << result->getString(2).c_str() << ", " << result->getInt(3) << ")";

  delete result;
  delete pstmt;
};

auto test_update = [](sql::Connection *conn) {
  auto pstmt = conn->prepareStatement(
      "UPDATE inventory SET quantity = ? WHERE name = ?");
  pstmt->setInt(1, 200);
  pstmt->setString(2, "banana");
  pstmt->executeQuery();

  delete pstmt;
};

auto test_delete = [](sql::Connection *conn) {
  auto pstmt = conn->prepareStatement("DELETE FROM inventory WHERE name = ?");
  pstmt->setString(1, "orange");
  auto result = pstmt->executeQuery();

  BOOST_LOG_TRIVIAL(debug) << "Row deleted";

  delete pstmt;
  delete result;
};

BOOST_AUTO_TEST_CASE(test_mysqlcppconn) {
  auto properties = sql::ConnectOptionsMap{};
  properties["hostName"] = "db";
  properties["userName"] = "root";
  properties["password"] = "password";
  properties["schema"] = "app";
  properties["port"] = 3306;
  properties["OPT_RECONNECT"] = true;

  auto driver = get_driver_instance();
  auto conn = driver->connect(properties);

  test_create(conn);
  test_read(conn);
  test_update(conn);
  test_delete(conn);

  delete conn;

  BOOST_TEST(true);
}
