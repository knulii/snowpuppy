FROM debian:stretch
LABEL maintainer="SnowPuppyCoin Developers <dev@snowpuppycoin.org>"
LABEL description="Dockerised SnowPuppyCoinCore, built from Travis"

RUN apt-get update && apt-get -y upgrade && apt-get clean && rm -fr /var/cache/apt/*

COPY bin/* /usr/bin/
