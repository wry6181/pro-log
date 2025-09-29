FROM alpine:3.17.0 AS build

RUN apk add --no-cache \
    cmake \
    make \
    g++ \
    libc-dev

WORKDIR /pro-log

COPY src/ ./src/
COPY CMakeLists.txt .

WORKDIR /pro-log/build

RUN cmake -DCMAKE_BUILD_TYPE=Release .. && \
    cmake --build . --parallel 8

ENTRYPOINT ["./src/CLI"]
