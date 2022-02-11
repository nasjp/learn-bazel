cc_test(
    name = "hello",
    srcs = ["hello-test.cpp"],
    deps = [
        ":util",
        "//main:hello-greet",
        "//third_party:libmysqlcppconn",
    ],
)

cc_library(
    name = "util",
    deps = [
        "@boost//:log",
        "@boost//:test.a",
        "@boost//:test.so",
    ],
)
