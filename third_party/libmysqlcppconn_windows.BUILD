package(default_visibility = ["//visibility:public"])

cc_library(
    name = "libmysqlcppconn_windows",
    srcs = glob([
        "lib64/*.dll",
        "lib64/**/*.dll",
    ]),
    hdrs = glob([
        "include/jdbc/cppconn/*.h",
    ]),
    includes = [
        "include/**",
    ],
    strip_include_prefix = "include/",
)
