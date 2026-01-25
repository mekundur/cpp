#!/bin/bash

PROGRAM=./scalarConverter

# Each test: input | expected char | expected int | expected float | expected double
tests=(
  # Subject examples
  "'a'|char: 'a'|int: 97|float: 97.0f|double: 97.0"
  "0|char: Non displayable|int: 0|float: 0.0f|double: 0.0"
  "42|char: '*'|int: 42|float: 42.0f|double: 42.0"
  "42.0f|char: '*'|int: 42|float: 42.0f|double: 42.0"
  "42.0|char: '*'|int: 42|float: 42.0f|double: 42.0"
  "-4.2f|char: impossible|int: -4|float: -4.2f|double: -4.2"
  "-4.2|char: impossible|int: -4|float: -4.2f|double: -4.2"

  # Pseudo literals
  "nan|char: impossible|int: impossible|float: nanf|double: nan"
  "nanf|char: impossible|int: impossible|float: nanf|double: nan"
  "+inf|char: impossible|int: impossible|float: inff|double: inf"
  "+inff|char: impossible|int: impossible|float: inff|double: inf"
  "-inf|char: impossible|int: impossible|float: -inff|double: -inf"
  "-inff|char: impossible|int: impossible|float: -inff|double: -inf"

  # Integer limits
  "-2147483648|char: impossible|int: -2147483648|float: -2147483648.0f|double: -2147483648.0"
  "2147483647|char: impossible|int: 2147483647|float: 2.14748e+09f|double: 2147483647.0"

  # Floating-point limits
  "340282346638528859811704183484516925440.0f|char: impossible|int: impossible|float: 3.40282e+38f|double: 3.40282e+38" # FLT_MAX
  "1.7976931348623157e+308|char: impossible|int: impossible|float: inff|double: 1.79769e+308" # DBL_MAX

  # Large integer within range but imprecise
  "999999999999999999999999999999|char: impossible|int: impossible|float: 1e+30f|double: 1e+30"

  # Edge case: absurd exponent → impossible
  "-1.7976931348623158e+355933333|char: impossible|int: impossible|float: impossible|double: impossible"

  # Invalid inputs
  "abcd|char: impossible|int: impossible|float: impossible|double: impossible"
  "123abc|char: impossible|int: impossible|float: impossible|double: impossible"
)

for t in "${tests[@]}"; do
  IFS="|" read -r input exp_char exp_int exp_float exp_double <<< "$t"
  echo ">>> Test: $input"
  
  output=$($PROGRAM "$input")

  # Extract actual lines
  act_char=$(echo "$output" | grep "^char:")
  act_int=$(echo "$output" | grep "^int:")
  act_float=$(echo "$output" | grep "^float:")
  act_double=$(echo "$output" | grep "^double:")

  # Compare each
  [[ "$act_char" == "$exp_char" ]] && echo "  $act_char ✅" || echo "  $act_char ❌ (expected $exp_char)"
  [[ "$act_int" == "$exp_int" ]] && echo "  $act_int ✅" || echo "  $act_int ❌ (expected $exp_int)"
  [[ "$act_float" == "$exp_float" ]] && echo "  $act_float ✅" || echo "  $act_float ❌ (expected $exp_float)"
  [[ "$act_double" == "$exp_double" ]] && echo "  $act_double ✅" || echo "  $act_double ❌ (expected $exp_double)"

  echo "-----------------------------------"
done

