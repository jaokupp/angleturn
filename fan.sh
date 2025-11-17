#!/bin/bash

echo "Installing fan controller..."

# คอมไพล์
g++ fan.cpp -o fan

# ย้ายไป /usr/local/bin
sudo mv fan /usr/local/bin/fan
sudo chmod +x /usr/local/bin/fan

echo "Done! Run with: sudo fan"
