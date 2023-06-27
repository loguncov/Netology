FROM ubuntu:20.04
RUN apt-get update && apt-get install -y g++ clang
COPY . /app
WORKDIR /app
RUN g++ -o output_gcc main.cpp
RUN clang++ -o output_clang main.cpp
