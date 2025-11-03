# Karatsuba Multiplication
# Aim: To multiply two long integers faster than normal multiplication

def karatsuba(x, y):
    # Base case: if numbers are small, multiply directly
    if x < 10 or y < 10:
        return x * y

    # Find the number of digits
    n = max(len(str(x)), len(str(y)))
    m = n // 2  # midpoint

    # Split the numbers
    power = 10 ** m
    a = x // power   # higher part of first number
    b = x % power    # lower part of first number
    c = y // power   # higher part of second number
    d = y % power    # lower part of second number

    # Recursive multiplications
    ac = karatsuba(a, c)
    bd = karatsuba(b, d)
    ad_plus_bc = karatsuba(a + b, c + d) - ac - bd

    # Combine results
    return (ac * 10 ** (2 * m)) + (ad_plus_bc * 10 ** m) + bd


# --- Main Program ---
x = int(input("Enter first number: "))
y = int(input("Enter second number: "))

print("\nMultiplying using Karatsuba Algorithm...\n")
result = karatsuba(x, y)

print(f"The product of {x} and {y} is: {result}")
