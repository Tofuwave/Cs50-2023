while True:
    user_input = input("How many '#' do you want (1 to 8)? ")


    if user_input.isdigit():
        num_rows = int(user_input)

        if 1 <= num_rows <= 8:
            break
        else:
            print("Please enter a number between 1 and 8.")
    else:
        print("Invalid input. Please enter a valid number.")

# Now, print the block of stairs with the requested number of '#'
for i in range(1, num_rows + 1):
    # Inner loop for spaces (before '#')
    for j in range(num_rows - i):
        print(' ', end='')

    # Inner loop for printing '#' characters
    for k in range(i):
        print('#', end='')

    # Move to the next line after printing each row
    print()