cc_library(
    name = "hello-greet",
    srcs = ["hello-greet.cpp"],
    hdrs = ["hello-greet.h"],
    visibility = ["//test:__pkg__"],
    deps = [
        "//proto:hey_cc_grpc",
        "@boost//:log",
        "@com_github_grpc_grpc//:grpc++",
    ],
)

cc_binary(
    name = "hello-world",
    srcs = ["main.cpp"],
    deps = [
        ":hello-greet",
    ],
)
