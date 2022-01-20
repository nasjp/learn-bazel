#include "hello-greet.h"

using hey::Hey;

int main(int, char*[]) {
  const auto h = Hey();

  BOOST_LOG_TRIVIAL(debug) << h.service_full_name();

  return 0;
}
