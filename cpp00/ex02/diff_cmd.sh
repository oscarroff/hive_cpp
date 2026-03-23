#!/bin/bash

diff <(cut -c 19- 19920104_091532.log) <(./DreamJob| cut -c 19-)
