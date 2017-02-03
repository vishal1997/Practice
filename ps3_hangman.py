# Hangman game
#

# -----------------------------------
# Helper code
# You don't need to understand this helper code,
# but you will have to know how to use the functions
# (so be sure to read the docstrings!)

import random

WORDLIST_FILENAME = "words.txt"

def loadWords():
    """
    Returns a list of valid words. Words are strings of lowercase letters.
    
    Depending on the size of the word list, this function may
    take a while to finish.
    """
    print("Loading word list from file...")
    # inFile: file
    inFile = open(WORDLIST_FILENAME, 'r')
    # line: string
    line = inFile.readline()
    # wordlist: list of strings
    wordlist = line.split()
    print("  ", len(wordlist), "words loaded.")
    return wordlist

def good_guess(letter,secretWord):
    for char in secretWord:
        if char==letter:
            return True
    return False
    
def chooseWord(wordlist):
    """
    wordlist (list): list of words (strings)

    Returns a word from wordlist at random
    """
    return random.choice(wordlist)

# end of helper code
# -----------------------------------

# Load the list of words into the variable wordlist
# so that it can be accessed from anywhere in the program
wordlist = loadWords()
def isWordGuessed(secretWord, lettersGuessed):
    '''
    secretWord: string, the word the user is guessing
    lettersGuessed: list, what letters have been guessed so far
    returns: boolean, True if all the letters of secretWord are in lettersGuessed;
      False otherwise
    '''
    # FILL IN YOUR CODE HERE...
    for char in secretWord:
        if char not in lettersGuessed:
            return False
    return True


def getGuessedWord(secretWord, lettersGuessed):
    '''
    secretWord: string, the word the user is guessing
    lettersGuessed: list, what letters have been guessed so far
    returns: string, comprised of letters and underscores that represents
      what letters in secretWord have been guessed so far.
    '''
    # FILL IN YOUR CODE HERE...
    word=''
    for char in secretWord:
        if char not in lettersGuessed:
            word+="_ "
        else:
            word+=char
    return word



def getAvailableLetters(lettersGuessed):
    '''
    lettersGuessed: list, what letters have been guessed so far
    returns: string, comprised of letters that represents what letters have not
      yet been guessed.
    '''
    # FILL IN YOUR CODE HERE...
    letters="abcdefghijklmnopqrstuvwxyz"
    availLetters=''
    for char in letters:
        if char not in lettersGuessed:
            availLetters+=char
    return availLetters
    
def check(availableLetters,guess):
    flag=0
    for char in availableLetters:
        if char in guess:
            flag=1
    if flag==1:
        return False
    else :
        return True
    
    
def hangman(secretWord):
    '''
    secretWord: string, the secret word to guess.

    Starts up an interactive game of Hangman.

    * At the start of the game, let the user know how many 
      letters the secretWord contains.

    * Ask the user to supply one guess (i.e. letter) per round.

    * The user should receive feedback immediately after each guess 
      about whether their guess appears in the computers word.

    * After each round, you should also display to the user the 
      partially guessed word so far, as well as letters that the 
      user has not yet guessed.

    Follows the other limitations detailed in the problem write-up.
    '''
    # FILL IN YOUR CODE HERE...
    
    print("Welcome to the game, Hangman!")
    print("I am thinking of a word that is "+str(len(secretWord))+" letters long.")
    lettersGuessed=''
    guess=''
    word=''
    i=8
    while i>0:
        print("-----------")
        print("You have "+str(i)+" guesses left")
        availableLetters=getAvailableLetters(lettersGuessed)
        print("Available Letters: "+str(availableLetters))
        guess=str(input("Please guess a letter: "))
        lowerGuess=guess.lower()
        if check(availableLetters,lowerGuess):
            print("Oops! You've already guessed that letter: "+str(word))
            continue
        else:
            lettersGuessed+=lowerGuess
            word=getGuessedWord(secretWord, lettersGuessed)
            if good_guess(lowerGuess, secretWord):
                print("Good guess: "+str(word))
            else:
                print("Oops! That letter is not in my word: "+str(word))
                i-=1
            if isWordGuessed(secretWord, lettersGuessed):
                print("-----------")
                print("Congratulations, you won!")
                break
    if(i==0):
        print("-----------")
        print("Sorry, you ran out of guesses. The word was "+str(secretWord)+".")
# When you've completed your hangman function, uncomment these two lines
# and run this file to test! (hint: you might want to pick your own
# secretWord while you're testing)

secretWord = chooseWord(wordlist).lower()
hangman(secretWord)
