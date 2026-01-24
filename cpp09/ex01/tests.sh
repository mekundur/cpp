#!/bin/bash

echo "=== RPN Test Suite ==="

# Function to run a test
run_test() {
    expr="$1"
    expected="$2"
    output=$(./RPN "$expr" 2>&1)   # capture stdout and stderr
    if [ "$output" = "$expected" ]; then
        echo "✅ ./RPN \"$expr\" => $output"
    else
        echo "❌ ./RPN \"$expr\""
        echo "   Expected: $expected"
        echo "   Got:      $output"
    fi
}

# Provided cases
run_test "2 5 3 * -" "-13"
run_test "8 9 * 9 - 9 - 9 - 4 - 1 +" "42"
run_test "7 7 * 7 -" "42"
run_test "1 2 * 2 / 2 * 2 4 - +" "0"
run_test "9 1 -" "8"
run_test "9 1 +" "10"
run_test "9 1 /" "9"
run_test "1 2 +" "3"
run_test "9" "9"
run_test "5 5 5 5 + - *" "-25"
run_test "1 2 + 3" "Error"
run_test "7 7 * 7 - +" "Error"
run_test "9 0 /" "Error"
run_test "1 +" "Error"
run_test "(1 + 1)" "Error"
run_test "12 3 +" "Error"
run_test "a b +" "Error"
run_test "9 +" "Error"
run_test "9 5 +" "14"
run_test "9 5+" "Error"
run_test "9 5 + a +" "Error"

echo "=== End of tests ==="

