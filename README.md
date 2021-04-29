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

This part of the algorithm works by processing each block of 1024 bits from the message using the result from the previous block. This posed a problem for the first block which does not have a result from a previous block. The solution to this was to use an initial hash value consisting of eight 64-bit words. Each result is stored in a hash buffer which in turn stores the final hash digest of the entire processing phase [1].

###### Message Processing

Message processing is done upon the formatted input by taking one block of 1024 bits a time. The message block is made into eighty 'Words', each having a size of 64 bits. The main part of the message processing is the Rounds. Each round takes three things: One 'Word', the output of the previous round and the SHA-512 constant. After it processes the 3 above items it gives an output of 512 bits, this is then repeated 80 Rounds. After the 80th Round the output is then added to previous message processing phase [1].

###### Output

After every block goes through the message processing phase, we get the final 512-bit Hash value of the original message.


The SHA-512 serves significant importance in providing security. The algorithm is commonly used for email address hashing, password hashing, and digital record verification. It is also used in blockchain technology.

## Questions and Answers:
#### Why can't we reverse the SHA512 algorithm to retrieve the original message from a hash digest?

The SHA-512 algorithm is a hashing function which is a mathematical algorithm that maps data of arbitrary size (often called the "message") to a bit array of a fixed size (the "hash value", "hash", or "message digest") [4]. It cannot be reversed due to it being a one-way function - a one-way function is a function that is easy to compute on every input, but hard to invert given the image of a random input [5].

In a hash function hundreds of one way operations take place sequentially, using the results from the earlier operation in the next operation. If trying to reverse it you would have to guess the two inputs in the later stage and then work back through the algorithm, but if you guess a number wrong there will be inconsistencies in the next stages. Using trial and error to guess the combinations to get a collision - a collision is when newly inserted key maps to an already occupied slot in a hash table [6] - is computationally expensive as there are to many combinations to guess.

SHA-512 is theoretically possible to reverse, but it is realistically impossible due to how computationally expensive it will be, and the time taken will be much longer than a few million years. SHA-512 is bit dependent which means tha each bit of the output is dependent upon every bit in the input. This prevents anyone from splitting the algorithm up and trying to reverse calculate an input from each bit of the output hash separately [7]. To solve just one output bit, you must know the entire input.

Two features that hashing algorithms use in making them non-reversible are: "The Avalanche Effect" and "Nonlinearity." The avalanche effect which means that a small change in the input results in a significant change in the output, making it statistically indistinguishable from random [8]. Since the output changes so dramatically with each input bit change, this stops anyone from building up relationships between inputs and outputs. Nonlinearity prevents anyone from using algebra techniques to solve the input from a given output. Hashing algorithms use many combinations of linear and non-linear operations.

In conclusion it is realistically impossible to reverse the SHA-512 algorithm to retrieve the original message from the hash digest.


#### Can you design an algorithm that, given enough time, will find input messages that give each of the possible 512-bit strings?

#### How difficult is it to find a hash digest beginning with at least twelve zeros?

There is an increase in difficulty with finding a hash digest beginning with twelve zeros, for every zero thats needed to be at the beginning of a hash digest the difficulty increases as well. The reason behind having twelve or more leading zeros is due to the concept ["Proof of Work"](https://en.wikipedia.org/wiki/Proof_of_work#:~:text=Proof%20of%20work%20(PoW)%20is,minimal%20effort%20on%20their%20part.). Proof of work (PoW) is a form of cryptographic zero-knowledge proof in which one party (the prover) proves to others (the verifiers) that a certain amount of computational effort has been expended for some purpose [9].

Bitcoin is a very good example of proving that there is a high level of difficulty with having a number of leading zeros at the beginning of a hash digest. Bitcoin is a proof-of-work cryptocurrency that is based on the [Hashcash](https://en.wikipedia.org/wiki/Hashcash) PoW.Bitcoin use the SHA-256 hashing function to generate a 64-digit hexadecimal number. Blocks in the blockchain have another field which is called ["The Nonce"](https://www.investopedia.com/terms/n/nonce.asp#:~:text=A%20nonce%20is%20an%20abbreviation,blockchain%20miners%20are%20solving%20for.) which stands for number used only once. The Nonce is an integer number and along with the Block Number, Data and previous hash the Nonce serves as an input to the SHA-256 function to calculate the current block's hash. The nonce is designed to be totally under the user control providing the user with a mechanism to vary the current blocks hash without changing the data inside it.

With bitcoin there is a minimal target for a hash set every two weeks, anything above the target is rejected and anything below the target is accepted. The important part about the target is the amount of leading zeros which represent a fixed-size number that determines its magnitude. Every leading zero reduces the numbers magnitude by a factor of sixteen. For this example we will say there are twelve leading zeros in the target, meaning the total of valid hashes is 16^52 (64-12=52). Therefore, the probability that a randomly picked hash is valid can be calculated as:

<img src="https://latex.codecogs.com/svg.image?16^{52}/16^{52}&space;=&space;16^{-12}&space;=&space;0.00000000000003%" title="16^{52}/16^{52} = 16^{-12} = 0.00000000000003%" />

The above is the probability that any given Nonce value will generate a valid hash. From seeing the probability, I came to the conclusion that the difficulty of finding a hash digest beginning with twelve zeros is very high and it takes a great amount of computation to generate this value.

## References & Research

- [1] SHA-512 Explained: https://medium.com/@zaid960928/cryptography-explaining-sha-512-ad896365a0c1#:~:text=SHA%2D512%20is%20a%20hashing,digital%20certificates%20and%20even%20blockchains.

- [2] Hashing Function: https://blog.jscrambler.com/hashing-algorithms/

- [3] SHA-512 Overview: https://blog.komodoplatform.com/en/sha-512/

- [4] Cryptographic hash function: https://en.wikipedia.org/wiki/Cryptographic_hash_function

- [5] One-way Function: https://en.wikipedia.org/wiki/One-way_function

- [6] Collision Meaning: https://www.geeksforgeeks.org/hashing-set-2-separate-chaining/

- [7] Reversing SHA-512: https://crypto.stackexchange.com/questions/45377/why-cant-we-reverse-hashes#:~:text=Bit%20dependency%3A%20A%20hash%20algorithm,of%20the%20output%20hash%20separately.

- [8] Avalanche Effect: https://www.wolfram.com/language/12/cryptography/demonstrate-the-avalanche-effect-of-a-hash-function.html

- [9] Proof of Work: https://en.wikipedia.org/wiki/Proof_of_work#:~:text=Proof%20of%20work%20(PoW)%20is,minimal%20effort%20on%20their%20part.