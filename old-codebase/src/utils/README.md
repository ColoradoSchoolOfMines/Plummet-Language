# Utils

This folder contains utility functions that are used across the entire project.

## cli-colors

Defines the `ColorFormat` class with the goal of making a easy to use and understand cross platform text format util. As of right now, Linux is the only supported platform for colors, all other platforms will default to plain text. Also defines `Style` and `Color` enums that provide a uniform means of format specification.

## test-suite

Defines the `TestSuite` class with the goal of being a light weight test suite that contributors don't need to setup (ex: gtest, boost).
