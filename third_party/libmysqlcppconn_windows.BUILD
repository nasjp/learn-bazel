package(default_visibility = ["//visibility:public"])

cc_library(
    name = "libmysqlcppconn_windows",
    srcs = glob([
        "lib/x86_64-linux-gnu/*.dll",
        "lib/x86_64-linux-gnu/**/*.dll",
    ]),
    hdrs = glob([
        "include/jdbc/cppconn/*.h",
    ]),
    includes = [
        "include/**",
    ],
    strip_include_prefix = "include/",
)
