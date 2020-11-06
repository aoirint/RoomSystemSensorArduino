#!/bin/bash

set -eu

arduino-cli upload -b arduino:avr:uno -p $1

