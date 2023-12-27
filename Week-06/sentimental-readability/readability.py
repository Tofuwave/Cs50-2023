from cs50 import get_string;
import string

sentence = get_string('Text: ')

letters = 0
word = 1
sentences = 0

for letter in sentence:
    if letter == "!" or letter == "?" or letter == ".":
        sentences += 1
    elif letter in string.punctuation:
        continue
    elif letter in string.whitespace:
        word += 1
    else:
        letters += 1

calcW = word / 100
lettersP = letters / calcW
sentencesP = sentences / calcW
liau = round((0.0588 * lettersP) - (0.296 * sentencesP) - 15.8)

if liau > 16:
    print('Grade 16+')
elif liau < 1:
    print('Before Grade 1')
else:
    print(f'Grade: {liau}')
