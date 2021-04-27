# TheoryOfAlgorithmsProject
Author: Mark Reilly

Student Number: G00357230

## Description
In this project I have written a program in the C programming language to calculate the [SHA512](https://www.nist.gov/publications/secure-hash-standard) value of an input file, using no external libaries only the C standard libary.

## Compilation
Prerequisites for Compilation
----------------------------- 
Prerequisites
- Ubuntu/Debian 

Source Code for Compilation
-----------------------------
- `git clone https://github.com/MarkReillyGMIT/TheoryOfAlgorithmsProject`
- `cd <compilation directory>`
-  Run `make test` this will run tests on any .txt file in the current directory and output sha512 value of the file and compare it to the correct sha512 value using sha512sum.

## Explanation
#### What is the SHA512 algorithm and why it is important.

SHA-512 is a hashing algorithm that performs a hashing function on some data given to it [1]. To understand what the SHA-512 algorithm is we need to firstly understand what a hashing function is. Hashing algorithms generate a fixed length result (the hash value) from a given input. It is a mathematical algorithm that maps data of arbitrary size to a hash of a fixed size. They are designed to be one-way functions, infeasible to invert [2]. 

SHA-512 or Secure Hash Algorithm 512 is a hashing algorithm used to convert data into a fixed-size string of 512bits (64bytes). Originally published in 2001, it was developed by the US Government's National Security Agency (NSA) [3]. It is designed with these four stages:

    - Input formatting.
    - Hash buffer initialization.
    - Message Processing.
    - Output.

###### Input Formatting

The SHA-512's formatted message has three parts: the original message, padding bits, size of original message. This is combined to a whole multiple of 1024 bits due to the message having to be processed in blocks of 1024 bits each. Padding bits is appended to the input message to achieve the desired length. After this, the size of the original message needs to be represented in 128 bits. Now that the padding bits and the size of the message have been appended, we are left with the completely formatted input for the SHA-512 algorithm [1].

###### Hash Buffer Initialization

This part of the algorithm works by processing each block of 1024 bits from the message using the result from the previous block. This posed a problem for the first block which does not have a result from a previos block. The solutuion to this was to use an inital hash value consisting of eight 64-bit words. Each result is stored in a hash buffer which in turn stores the final hash digest of the entire processing phase [1].

###### Message Processing 

Message processing is done upon the formatted input by taking one block of 1024 bits a time. The messge block is made into eighty 'Words' each having a size of 64 bits. The main part of the message processing is the Rounds. Each round takes 3 things: One 'Word', the output of the previous round and the SHA-512 constant. After it processes the 3 above items it gives an output of 512 bits, this is then repeated 80 Rounds. After the 80th Round the output is then added to previous message processing phase [1].

###### Output

After every block goes through the message processing phase, we get the final 512-bit Hash value of the original message.


The SHA-512 serves significant importance in providing security. The algorithm is commonly used for email address hashing, password hashing, and digital record verification. It is also used in blockchain technology.

## Questions and Answers:
#### Why can't we reverse the SHA512 algorithm to retrieve the original message from a hash digest?

#### Can you design an algorithm that, given enough time, will find input messages that give each of the possible 512-bit strings?

#### How difficult is it to find a hash digest beginning with at least twelve zeros?

## Research



## References 

- [1] SHA-512 Explained: https://medium.com/@zaid960928/cryptography-explaining-sha-512-ad896365a0c1#:~:text=SHA%2D512%20is%20a%20hashing,digital%20certificates%20and%20even%20blockchains.

- [2] Hashing Function: https://blog.jscrambler.com/hashing-algorithms/

- [3] SHA-512 Overview: https://blog.komodoplatform.com/en/sha-512/