cc_test(
    name = "hello-test",
    srcs = ["hello-test.cc"],
    copts = ["-Iexternal/gtest/include"],
    deps = [
        "//main:hello-greet",
        "@com_google_googletest//:gtest_main",
    ],
)
