LIBMYSQLCPPCONN = select({
    "@platforms//os:windows": ["@libmysqlcppconn_windows"],
    "//conditions:default": ["@libmysqlcppconn_linux"],
})

cc_test(
    name = "hello",
    srcs = ["hello-test.cpp"],
    deps = [
        ":util",
        "//main:hello-greet",
    ] + LIBMYSQLCPPCONN,
)

cc_library(
    name = "util",
    deps = [
        "@boost//:log",
        "@boost//:test.a",
        "@boost//:test.so",
    ],
)
