def is_narcissistic(number):
    num_str = str(number)
    num_digits = len(num_str)
    sum_of_powers = sum(int(digit) ** num_digits for digit in num_str)

    return sum_of_powers == number

num = int(input("Enter a number: "))
print(is_narcissistic(num))
