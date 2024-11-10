# Text Document Parsing and Query System

## Overview

This project implements a **C program** that parses a text document into its components: paragraphs, sentences, and words. It also includes a **query system** that allows users to retrieve specific paragraphs, sentences, or words from the document based on the user's input.

## Features

- **Text Document Parsing:**  
  The program parses a raw text document into **paragraphs**, **sentences**, and **words**.
  
- **Query System:**  
  The system allows three types of queries:
  1. Retrieve a **specific paragraph**.
  2. Retrieve a **specific sentence** from a paragraph.
  3. Retrieve a **specific word** from a sentence in a paragraph.

## Data Structure

The document is represented by a 4-dimensional array:

- **Document:** `char**** document`
  - The document is broken down into **paragraphs**.
  - Each paragraph contains **sentences**.
  - Each sentence is made up of **words**.
  - Each word is a string of characters (letters only).

## Input Format

1. **Number of paragraphs:**  
   The first input is an integer representing the number of paragraphs in the document.
   
2. **Paragraphs:**  
   Each paragraph is a string, and each sentence in the paragraph is separated by a period (`.`). Words in a sentence are separated by spaces.

3. **Queries:**  
   The program accepts multiple queries, where each query can be of the following types:
   
   - **Type 1:** Retrieve a specific paragraph.
   - **Type 2:** Retrieve a specific sentence from a paragraph.
   - **Type 3:** Retrieve a specific word from a sentence in a paragraph.

## Functions

### `char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n)`

- Retrieves the `k`-th word in the `m`-th sentence of the `n`-th paragraph.

### `char** kth_sentence_in_mth_paragraph(char**** document, int k, int m)`

- Retrieves the `k`-th sentence in the `m`-th paragraph.

### `char*** kth_paragraph(char**** document, int k)`

- Retrieves the `k`-th paragraph.

### `char**** get_document(char* text)`

- Parses the input text and builds the hierarchical document structure (`char****`).

### `char* get_input_text()`

- Reads input from the user and returns it as a string.

### `void print_word(char* word)`

- Prints the provided word.

### `void print_sentence(char** sentence)`

- Prints the provided sentence.

### `void print_paragraph(char*** paragraph)`

- Prints the entire paragraph.

### Query Input Format

- **Type 1 (Paragraph):**  
  Input: Integer `k`, the paragraph number (1-indexed).
  
- **Type 2 (Sentence in Paragraph):**  
  Input: Two integers `k` (sentence number) and `m` (paragraph number).
  
- **Type 3 (Word in Sentence of Paragraph):**  
  Input: Three integers `k` (word number), `m` (sentence number), and `n` (paragraph number).

## Output Format

For each query, the program will output the corresponding component:
- **Type 1:** The entire paragraph.
- **Type 2:** The specific sentence from the paragraph.
- **Type 3:** The specific word from the sentence.

### Example Input
2
Learning C is fun.
Learning pointers is more fun.It is good to have pointers.
3
1 2
2
5
6
2 1 1
4
3 1 1 1

### Example Output
Learning pointers is more fun.It is good to have pointers.
Learning C is fun
Learning


