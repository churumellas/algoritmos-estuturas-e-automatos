load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_test(
    name = "tests",
    srcs = glob(["**/*.cc"]),
    deps = [
        "//src:lista-simples",
        "@googletest//:gtest_main",
    ],
)