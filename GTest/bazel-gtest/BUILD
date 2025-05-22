cc_library(
    name = "math_utils",
    srcs = ["math_utils.cc"],
    hdrs = ["math_utils.h"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "string_calculator",
    srcs = ["string_calculator.cc"],
    hdrs = ["string_calculator.h"],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "math_utils_test",
    size = "small",
    srcs = ["math_utils_test.cc"],
    deps = [
        ":math_utils",
        "@googletest//:gtest",
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "string_calculator_test",
    size = "small",
    srcs = ["string_calculator_test.cpp"],  # Make sure this matches your file name
    deps = [
        ":string_calculator",
        "@googletest//:gtest",
        "@googletest//:gtest_main",
    ],
)