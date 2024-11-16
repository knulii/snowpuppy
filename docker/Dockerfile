FROM debian:stretch
LABEL maintainer="Snowpuppycoin Developers <dev@snowpuppycoin.org>"
LABEL description="Dockerised SnowpuppycoinCore, built from Travis"

RUN apt-get update && apt-get -y upgrade && apt-get clean && rm -fr /var/cache/apt/*

COPY bin/* /usr/bin/
