#!/bin/bash
# use testnet settings,  if you need mainnet,  use ~/.snowpuppycoincore/snowpuppycoind.pid file instead
snowpuppycoin_pid=$(<~/.snowpuppycoincore/testnet3/snowpuppycoind.pid)
sudo gdb -batch -ex "source debug.gdb" snowpuppycoind ${snowpuppycoin_pid}
