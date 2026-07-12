# C++ Transformer From Scratch

An educational implementation of the Transformer architecture written entirely in modern C++ without using external machine learning frameworks such as PyTorch or TensorFlow.

The objective of this project is to understand every component of a Transformer by implementing each module from the ground up, including linear algebra, tokenization, embeddings, attention mechanisms, optimization, and training.

---

## Features

- Custom Matrix and Vector library
- Word-based tokenizer
- Embedding layer
- Positional Encoding *(planned)*
- Multi-Head Self Attention *(planned)*
- Feed Forward Network *(planned)*
- Layer Normalization *(planned)*
- Encoder *(planned)*
- Decoder *(planned)*
- Adam Optimizer *(planned)*
- Transformer Training *(planned)*

---

## Project Structure

```text
.
├── math/
│   ├── Matrix
│   ├── Vector
│   ├── Random
│   ├── Math
│   └── Activation
│
├── tokenizer/
│   └── tokenizer
│
├── test/
│   ├── test
│   └── test_corpus
│
└── main
```

---

## Roadmap

- [x] Matrix class
- [x] Vector class
- [x] Activation functions
- [x] Random initialization
- [x] Tokenizer
- [ ] Embedding
- [ ] Positional Encoding
- [ ] Linear Layer
- [ ] Self Attention
- [ ] Multi-Head Attention
- [ ] Feed Forward Network
- [ ] Layer Normalization
- [ ] Encoder Layer
- [ ] Transformer Encoder
- [ ] Decoder
- [ ] Training Pipeline

---

## Purpose

This project is intended for educational purposes and aims to provide a complete understanding of the Transformer architecture by implementing every component from scratch.

No external machine learning libraries are used.

---

## References

- Vaswani et al. — *Attention Is All You Need* (2017)
- Dive into Deep Learning
- Deep Learning (Goodfellow, Bengio, Courville)
