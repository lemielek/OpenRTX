/***************************************************************************
 *   Copyright (C) 2021 - 2022 by Federico Amedeo Izzo IU2NUO,             *
 *                                Niccolò Izzo IU2KIN                      *
 *                                Wojciech Kaczmarski SP5WWP               *
 *                                Frederik Saraci IU2NRO                   *
 *                                Silvano Seva IU2KWO                      *
 *                                                                         *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, see <http://www.gnu.org/licenses/>   *
 ***************************************************************************/

#ifndef M17_DSP_H
#define M17_DSP_H

#ifndef __cplusplus
#error This header is C++ only!
#endif

#include <dsp.h>
#include <array>

namespace M17
{

/*
 * Coefficients for M17 RRC filters
 */
static constexpr std::array<float, 81> rrc_taps_48k =
{
    -0.003195702904062073, -0.002930279157647190, -0.001940667871554463,
    -0.000356087678023658,  0.001547011339077758,  0.003389554791179751,
     0.004761898604225673,  0.005310860846138910,  0.004824746306020221,
     0.003297923526848786,  0.000958710871218619, -0.001749908029791816,
    -0.004238694106631223, -0.005881783042101693, -0.006150256456781309,
    -0.004745376707651645, -0.001704189656473565,  0.002547854551539951,
     0.007215575568844704,  0.011231038205363532,  0.013421952197060707,
     0.012730475385624438,  0.008449554307303753,  0.000436744366018287,
    -0.010735380379191660, -0.023726883538258272, -0.036498030780605324,
    -0.046500883189991064, -0.050979050575999614, -0.047340680079891187,
    -0.033554880492651755, -0.008513823955725943,  0.027696543159614194,
     0.073664520037517042,  0.126689053778116234,  0.182990955139333916,
     0.238080025892859704,  0.287235637987091563,  0.326040247765297220,
     0.350895727088112619,  0.359452932027607974,  0.350895727088112619,
     0.326040247765297220,  0.287235637987091563,  0.238080025892859704,
     0.182990955139333916,  0.126689053778116234,  0.073664520037517042,
     0.027696543159614194, -0.008513823955725943, -0.033554880492651755,
    -0.047340680079891187, -0.050979050575999614, -0.046500883189991064,
    -0.036498030780605324, -0.023726883538258272, -0.010735380379191660,
     0.000436744366018287,  0.008449554307303753,  0.012730475385624438,
     0.013421952197060707,  0.011231038205363532,  0.007215575568844704,
     0.002547854551539951, -0.001704189656473565, -0.004745376707651645,
    -0.006150256456781309, -0.005881783042101693, -0.004238694106631223,
    -0.001749908029791816,  0.000958710871218619,  0.003297923526848786,
     0.004824746306020221,  0.005310860846138910,  0.004761898604225673,
     0.003389554791179751,  0.001547011339077758, -0.000356087678023658,
    -0.001940667871554463, -0.002930279157647190, -0.003195702904062073,
};

static constexpr std::array<float, 41> rrc_taps_24k =
{
    -0.00451938415438936, -0.00274450532197076,  0.00218779365365964,
     0.00673430845820838,  0.00682318809319229,  0.00135581524631680,
    -0.00599438920196964, -0.00869773330332975, -0.00241007626827605,
     0.0102043146279916,   0.0189814134484353,   0.0119494155102909,
    -0.0151820458389266,  -0.0516157561976790,  -0.0720949100387685,
    -0.0474535336210882,   0.0391686342706687,   0.179164496628150,
     0.336694345124862,    0.461088271869920,    0.508340710642860,
     0.461088271869920,    0.336694345124862,    0.179164496628150,
     0.0391686342706687,  -0.0474535336210882,  -0.0720949100387685,
    -0.0516157561976790,  -0.0151820458389266,   0.0119494155102909,
     0.0189814134484353,   0.0102043146279916,  -0.00241007626827605,
    -0.00869773330332975, -0.00599438920196964,  0.00135581524631680,
     0.00682318809319229,  0.00673430845820838,  0.00218779365365964,
    -0.00274450532197076, -0.00451938415438936
};

/*
 * FIR implementations of the RRC filter for baseband audio generation.
 */
extern Fir< std::tuple_size< decltype(rrc_taps_48k) >::value > rrc_48k;
extern Fir< std::tuple_size< decltype(rrc_taps_24k) >::value > rrc_24k;

} /* M17 */

#endif /* M17_DSP_H */
