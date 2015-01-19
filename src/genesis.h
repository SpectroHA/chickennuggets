// By mammix2@hotmail.com
// Moving the genesis block hashes out into a separate file makes it quicker to rebuild
// multiple times when trying to find the genesis block hash 0

#ifndef GENESIS_H
#define GENESIS_H

static const uint256 hashGenesisBlock("00000a7f6163f1b841007ce7f0461b870a1721b1559a049a971452a32d4e4161");
static const uint256 hashGenesisBlockTestNet("00000bfc2c5b172b52575609319f9ed43700e43d9ae134255ea2dd529142144c");

#endif // GENESIS_H
