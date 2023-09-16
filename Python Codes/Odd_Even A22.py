#Python Program to demonstrate odd_even number
num = input("Enter an integer: ")

#using exception handling
try:
    number = int(num)
    if number % 2 == 0:
        print(f"{number} is even.") #f string formatter
    else:
        print(f"{number} is odd.") #f string formatter
except ValueError:
    print("Enter valid data. The input is not a valid integer.")
