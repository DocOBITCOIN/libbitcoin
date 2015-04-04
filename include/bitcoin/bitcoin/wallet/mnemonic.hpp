/*
 * Copyright (c) 2011-2015 libbitcoin developers (see AUTHORS)
 *
 * This file is part of libbitcoin.
 *
 * libbitcoin is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef LIBBITCOIN_MNEMONIC_HPP
#define LIBBITCOIN_MNEMONIC_HPP

#include <string>
#include <bitcoin/bitcoin/compat.hpp>
#include <bitcoin/bitcoin/define.hpp>
#include <bitcoin/bitcoin/math/hash.hpp>
#include <bitcoin/bitcoin/utility/data.hpp>
#include <bitcoin/bitcoin/wallet/dictionary.hpp>

namespace libbitcoin {

/**
 * A valid mnemonic word count is evenly divisible by this number.
 */
BC_CONSTEXPR size_t mnemonic_word_multiple = 3;

/**
 * A valid seed byte count is evenly divisible by this number.
 */
BC_CONSTEXPR size_t mnemonic_seed_multiple = 4;

/**
 * Represents a mnemonic.
 */
typedef std::vector<std::string> string_list;

/**
 * Create a new mnenomic (list of words) from provided entropy and a dictionary
 * selection. The mnemonic can later be converted to a seed for use in wallet
 * creation. Entropy byte count must be evenly divisible by 4.
 */
BC_API string_list create_mnemonic(data_slice entropy,
    const wordlist &dictionary=language::en);

/**
 * Checks a mnemonic against a wordlist to determine if the
 * words are spelled correctly and the checksum matches.
 * The words must have been created using mnemonic encoding.
 */
BC_API bool validate_mnemonic(const string_list& mnemonic,
    const wordlist &dictionary);

/**
 * Checks that a mnemonic is valid in at least one of the provided languages.
 */
BC_API bool validate_mnemonic(const string_list& mnemonic,
    const wordlist_list& dictionaries=language::all);

/**
 * Convert a mnemonic and optional passphrase to a wallet-generation seed.
 * Any passphrase can be used and will change the resulting seed.
 */
BC_API long_hash decode_mnemonic(const string_list& mnemonic,
    const std::string& passphrase="");

} // namespace libbitcoin

#endif
