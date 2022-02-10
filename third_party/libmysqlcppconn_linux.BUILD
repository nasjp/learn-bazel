package(default_visibility = ["//visibility:public"])

cc_library(
    name = "libmysqlcppconn_linux",
    srcs = glob([
        "lib/x86_64-linux-gnu/*.so",
        "lib/x86_64-linux-gnu/*.so.*",
        "lib/x86_64-linux-gnu/**/*.so",
        "lib/x86_64-linux-gnu/**/*.so.*",
    ]),
    hdrs = glob([
        "include/mysql-cppconn-8/jdbc/cppconn/*.h",
    ]),
    includes = [
        "include/mysql-cppconn-8/**",
    ],
    strip_include_prefix = "include/mysql-cppconn-8/",
)
