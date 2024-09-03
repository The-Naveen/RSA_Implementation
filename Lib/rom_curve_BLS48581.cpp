/*
 * Copyright (c) 2012-2020 MIRACL UK Ltd.
 *
 * This file is part of MIRACL Core
 * (see https://github.com/miracl/core).
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "arch.h"
#include "ecp_BLS48581.h"

namespace BLS48581 {
/* Curve BLS48581 - Pairing friendly BLS curve */

#if CHUNK==16

#error Not supported

#endif

#if CHUNK==32

using namespace B584_29;

//*** rom curve parameters *****
// Base Bits= 29
// Ate Bits= 33
// G2 Table size= 36

const int CURVE_Cof_I= 0;
const BIG CURVE_Cof= {0x382,0xA,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0};
const int CURVE_B_I= 1;
const BIG CURVE_B= {0x1,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0};
const BIG CURVE_Order= {0xD671C01,0x52FF37E,0x10936846,0x1CB328CF,0x103C4CCB,0x1E682B11,0x5AA171,0x6989924,0x741969D,0xB961737,0xFEB5AF2,0x16797C00,0x1387A3F0,0x6B631A,0x13305857,0xBC46753,0x925E288,0x11C37C5,0x0,0x0,0x0};
const BIG CURVE_Gx= {0x115AF640,0x1E743991,0x79B630E,0x9B4BA74,0x11786CB7,0x1ED9B458,0x1BAF6F15,0xBB0B246,0x4584766,0x14EFB7CB,0x1154151A,0x1F73EEA8,0xBDBAEDF,0x3467B0D,0x15F83A1A,0xC1BC7E4,0x1F1E93F8,0x1D795B9E,0xB0D03CA,0x55EB36F,0x0};
const BIG CURVE_Gy= {0x2587A70,0xDDAEF1F,0x49AD5DB,0x6F5DEF7,0x11B2E35F,0x1BE143B6,0x8BD21FD,0xB0987DE,0x1E80F678,0x1CC57729,0xEDEFBFE,0x16E41DEF,0x1279DD41,0x52974C8,0xF27BFAE,0x149114AA,0xD1FB398,0xFC359D1,0x1D94C7E4,0x19DFB489,0x0};
const BIG CURVE_HTPC= {0x31193EC,0x1C9F85F0,0x1D6090C,0x5112C88,0x10D4620C,0x1F255473,0x1F5583B6,0x4F7AABD,0xCD0706B,0x14B125F7,0xECD8492,0x4D5AF8A,0xC755E26,0x2D4C018,0xB0B7761,0x1369CD4C,0x1FD42938,0x782EC54,0x17716BE5,0x1246919A,0x0};

const BIG CURVE_Bnx= {0x381,0xA,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0};

const BIG CURVE_Pxaaa= {0xCE8BFAB,0x1A7E85A5,0x85537B0,0xF2ECC64,0x1510317B,0x6C0248F,0x140C01,0x140C25E8,0x281A63C,0x168D4621,0x1BFDE6EA,0x1DE2AD88,0x64DB3A2,0xDE65BEF,0x1F1C0D13,0x1BD7577D,0x45A2775,0x11C11BFD,0x9E1C792,0xBAC2BB3,0x0};
const BIG CURVE_Pxaab= {0x16B47C57,0x134D9B33,0x1E850FC5,0xAAD4035,0x30FFD75,0x1186CBCB,0x13C30F1D,0x1FF4C4A0,0x214A76A,0x15FF6F8B,0xE50E802,0xFE9C38,0xF6DA123,0x111F4A93,0x1B660385,0x1D164576,0x86ABC07,0x9034D87,0x13889614,0xF892E7D,0x0};
const BIG CURVE_Pxaba= {0x55A3E6A,0x440AB65,0xCFC2D19,0x1E99BDAD,0x1D5FEA8E,0x1EFDDC3C,0x157C0A32,0x1E1A54DA,0xFFAE766,0xDE8C921,0x18058707,0x156B56D0,0x16957CCB,0x1BE53D36,0x1B2A6B88,0x178E7514,0x1853AD83,0x70D9750,0x663C4CD,0x3F998E0,0x0};
const BIG CURVE_Pxabb= {0x1B7FEAFE,0xD3819E5,0x2F0FC2,0x171969D,0xCA5231,0x292BE10,0x51A30C7,0x16364F37,0xE6EC143,0x11F0E3BB,0x862A57D,0x1F17C198,0x1B92A393,0x1F2C10DB,0x16B18BC,0x17FD1EB3,0x12954D4,0x2E3C6C0,0x973AD86,0x17C44318,0x0};
const BIG CURVE_Pxbaa= {0x13F8CCE5,0x1CE1D0E2,0x7532EDC,0x16BEE8D9,0x1AA80C65,0xAFE0C44,0x49D3EB5,0x9255CB1,0xC10B2EF,0x40CCEAD,0x6607E79,0xA70CD3,0x1F0E7C58,0x15AB3AF,0x1D742C59,0xC600F8C,0x4CAA9DD,0x1D1E2CC7,0x2CD644,0x717238C,0x0};
const BIG CURVE_Pxbab= {0xA3C093A,0x10026C8A,0x138CDC3C,0x12C1221F,0xF097FC7,0xF8BBB09,0x175D656A,0x1738162B,0x1EB57B40,0x1AE944CB,0x77D8E0,0x6E8303,0x58677BB,0xBBD1E8D,0xD773BC2,0x111EF71E,0x1E4ECDA0,0x101F8988,0x1FAC1CE1,0x192D8EF2,0x0};
const BIG CURVE_Pxbba= {0x750E057,0xB03F30,0x170CD539,0x16B61C40,0x2D63334,0x1F219261,0xCAAB472,0xBDF9E68,0x10FD0CAA,0x9D89E76,0x13BC47CA,0x16F4893,0x1908BA2C,0x1C295B6D,0x106CE744,0x1CCC1BD4,0x98908AE,0x1F80CBD2,0x118187B8,0x1736F2A3,0x0};
const BIG CURVE_Pxbbb= {0x1BC6AE34,0x10CED007,0x5F0FE13,0x15E5F93D,0x1FC44E56,0x1EB575FC,0x116151E6,0x16FC561A,0x164A7190,0x1F94E7F9,0x1E33F2A4,0xE514FF3,0xF741719,0x3DA908E,0xA77BEBD,0x563CBAF,0xC4F4AAA,0x2941312,0xBECAF7B,0x104FAB84,0x0};
const BIG CURVE_Pyaaa= {0xD2D7971,0x1F6E9FF2,0xB03FCC8,0xA025562,0x6D65904,0x15FBBF75,0x18F05666,0xDB15CA2,0xD90F733,0x17D13BA4,0x24188D6,0x86BF556,0x1B39EBFC,0x12BBF379,0x108E0166,0x4972316,0x16452F30,0xFD24B90,0x1B0DD6D7,0x1D6A66A,0x0};
const BIG CURVE_Pyaab= {0x16CD5665,0xA38EDC9,0x1FF1EC44,0x16846A4B,0xE2E588,0x1D04BEBB,0x1877484B,0x11255649,0x12C5C3D1,0x121D8F8C,0xBEC25AC,0x65F97E7,0x1D729647,0xF37DD00,0x108AE8C9,0x1B856EB4,0x11815FCA,0xA26D329,0x5E783FC,0x509B8EB,0x0};
const BIG CURVE_Pyaba= {0xA2A8474,0x1995293,0xEE3F79A,0x18F88DF8,0x52269CB,0x9AEA8D3,0x178BC307,0x194652BC,0x11515536,0xE874820,0x17DF5726,0xE0A288E,0x13A480D3,0x16AD88CE,0x1140C085,0x13DE585F,0x17036766,0x1F210F7D,0x17402148,0x166D4403,0x0};
const BIG CURVE_Pyabb= {0x841589D,0x1109ED49,0x194CDCC5,0x7B17143,0x5E578FB,0x1ED281F7,0xE84359E,0xEE84EE1,0xDCED281,0x199FD20,0xB226C89,0x245A4E8,0xB0E710E,0x7711EEC,0x1B4CD837,0x563859B,0x1BD47876,0x144111FD,0x1887B701,0x15D84B48,0x0};
const BIG CURVE_Pybaa= {0x2E50137,0x3C18FCC,0x13DE90FD,0xAFFBBBF,0x1137B088,0x9ACA2E,0x13D67D0C,0x9CA256C,0x8A1E2CA,0x111C66E7,0x16171DFE,0x2530AFD,0x159805F1,0xEC9DAD4,0x11506D0F,0xB44AA9B,0x1A5A8832,0x148B281F,0x88EA711,0x1A413AB4,0x0};
const BIG CURVE_Pybab= {0xF90BEE4,0x776E2C6,0x1B3CE965,0xB3DB044,0x12B679DA,0xCC6553,0xE78EABF,0xF8301A2,0x1F6824F4,0x6138420,0xA0D083A,0x156EA09F,0x182E2055,0x1915AC4E,0x159BAC59,0x17208435,0x1D5AD537,0x1289E99C,0x115CDADE,0xFA1A06E,0x0};
const BIG CURVE_Pybba= {0x1EB23986,0xA0FD757,0x6A98ACF,0x110802FB,0x13DCCC9E,0x7D31CFA,0x62D6ED0,0x118E964C,0x122C1FAB,0x11D14327,0x63D096B,0x10334DBF,0x15F14E4C,0xD8320A,0xD93F021,0x1F1400DE,0x1DFDD17A,0x112E1682,0x46F997A,0x112CECF0,0x0};
const BIG CURVE_Pybbb= {0x132718B6,0x133FFE5B,0x1A71575,0x158CDD08,0x13F748E5,0x6C62559,0x1505CC0,0x7D8E324,0x1E1AD033,0x14E18F4B,0xCE8FE39,0x1D95352A,0x149B6EF8,0x728643A,0x1C501AFA,0x36BC0D1,0x7E84F98,0x9C9D2E0,0x1FE240A7,0x6BC4A49,0x0};

#endif

#if CHUNK==64

using namespace B584_60;

// Base Bits= 60
// Ate Bits= 33
// G2 Table size= 36

const int CURVE_Cof_I= 0;
const BIG CURVE_Cof= {0x140000382L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L};
const int CURVE_B_I= 1;
const BIG CURVE_B= {0x1L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L};
const BIG CURVE_Order= {0x8A5FE6FCD671C01L,0xBE599467C24DA11L,0xC7CD0562303C4CCL,0x9D34C4C92016A85L,0xBC972C2E6E74196L,0x3F0B3CBE003FAD6L,0x615C0D6C635387AL,0xE2885E233A9CCC1L,0x2386F8A925L,0x0L};
const BIG CURVE_Gx= {0xBCE8732315AF640L,0x74DA5D3A1E6D8C3L,0x57DB368B11786CBL,0x665D859236EBDBCL,0x46A9DF6F9645847L,0xEDFFB9F75445505L,0xE86868CF61ABDBAL,0x93F860DE3F257E0L,0x40F2BAF2B73DF1EL,0x2AF59B7AC3L};
const BIG CURVE_Gy= {0xDBB5DE3E2587A70L,0xF37AEF7B926B576L,0xF77C2876D1B2E35L,0x78584C3EF22F487L,0xFFB98AEE53E80F6L,0xD41B720EF7BB7BEL,0xFEB8A52E991279DL,0xB398A488A553C9EL,0x31F91F86B3A2D1FL,0xCEFDA44F65L};
const BIG CURVE_HTPC= {0x393F0BE031193ECL,0xC28896440758243L,0xDBE4AA8E70D4620L,0x6B27BD55EFD560EL,0x24A9624BEECD070L,0xE2626AD7C53B361L,0xDD845A98030C755L,0x29389B4E6A62C2DL,0x5AF94F05D8A9FD4L,0x92348CD5DCL};
const BIG CURVE_Bnx= {0x140000381L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L};

const BIG CURVE_Pxaaa= {0x34FD0B4ACE8BFABL,0xB79766322154DECL,0x4D80491F510317L,0x3CA0612F4005030L,0xBAAD1A8C42281A6L,0x3A2EF156C46FF79L,0x344DBCCB7DE64DBL,0x2775DEBABBEFC70L,0x71E4A38237FA45AL,0x5D615D9A78L};
const BIG CURVE_Pxaab= {0x669B36676B47C57L,0x5556A01AFA143F1L,0x7630D979630FFD7L,0x6AFFA62504F0C3CL,0xABFEDF16214A7L,0x12307F4E1C3943AL,0xE1623E9526F6DAL,0xBC07E8B22BB6D98L,0x258512069B0E86AL,0x7C4973ECE2L};
const BIG CURVE_Pxaba= {0x488156CA55A3E6AL,0xEF4CDED6B3F0B46L,0xCBDFBB879D5FEA8L,0x66F0D2A6D55F028L,0xC1DBD19242FFAE7L,0xCCBAB5AB6860161L,0xAE237CA7A6D6957L,0xAD83BC73A8A6CA9L,0xF1334E1B2EA1853L,0x1FCCC70198L};
const BIG CURVE_Pxabb= {0x9A7033CBB7FEAFEL,0x10B8CB4E80BC3F0L,0x1C5257C200CA523L,0x43B1B279B9468C3L,0x5F63E1C776E6EC1L,0x393F8BE0CC218A9L,0x62F3E5821B7B92AL,0x54D4BFE8F5985ACL,0xEB6185C78D80129L,0xBE2218C25CL};
const BIG CURVE_Pxbaa= {0x39C3A1C53F8CCE5L,0x5B5F746C9D4CBB7L,0xD55FC1889AA80C6L,0xEF492AE589274FAL,0x9E48199D5AC10B2L,0xC5805386699981FL,0xB1642B5675FF0E7L,0xA9DD63007C675D0L,0x35913A3C598E4CAL,0x38B91C600BL};
const BIG CURVE_Pxbab= {0x2004D914A3C093AL,0x7960910FCE3370FL,0xA9F177612F097FCL,0x40B9C0B15DD7595L,0x3835D28997EB57BL,0x7BB037418181DF6L,0xEF0977A3D1A5867L,0xCDA088F7B8F35DCL,0x738603F1311E4EL,0xC96C7797EBL};
const BIG CURVE_Pxbba= {0x41607E60750E057L,0x4B5B0E205C3354EL,0xCBE4324C22D6333L,0xAA5EFCF3432AAD1L,0xF293B13CED0FD0CL,0xA2C0B7A449CEF11L,0x9D13852B6DB908BL,0x8AEE660DEA41B3L,0x61EE3F0197A4989L,0xB9B7951C60L};
const BIG CURVE_Pxbbb= {0xE19DA00FBC6AE34L,0x6AF2FC9E97C3F84L,0x9BD6AEBF9FC44E5L,0x90B7E2B0D458547L,0xA93F29CFF364A71L,0x719728A7F9F8CFCL,0xFAF47B5211CF741L,0x4AAA2B1E5D7A9DEL,0x2BDEC5282624C4FL,0x827D5C22FBL};
const BIG CURVE_Pyaaa= {0x3EDD3FE4D2D7971L,0x45012AB12C0FF32L,0x9ABF77EEA6D6590L,0x336D8AE5163C159L,0x35AFA27748D90F7L,0xBFC435FAAB09062L,0x59A577E6F3B39EL,0x2F3024B918B4238L,0x75B5DFA49721645L,0xEB53356C3L};
const BIG CURVE_Pyaab= {0x1471DB936CD5665L,0x8B423525FFC7B11L,0x2FA097D760E2E58L,0xD1892AB24E1DD21L,0x6B243B1F192C5C3L,0x64732FCBF3AFB09L,0xA325E6FBA01D729L,0x5FCADC2B75A422BL,0xE0FF144DA653181L,0x284DC75979L};
const BIG CURVE_Pyaba= {0x8332A526A2A8474L,0xBC7C46FC3B8FDE6L,0x1D35D51A652269CL,0x36CA3295E5E2F0CL,0xC99D0E904115155L,0xD370514475F7D5L,0x216D5B119D3A48L,0x67669EF2C2FC503L,0x8523E421EFB703L,0xB36A201DD0L};
const BIG CURVE_Pyabb= {0x6213DA92841589DL,0xB3D8B8A1E533731L,0x7BDA503EE5E578FL,0x817742770BA10D6L,0x224333FA40DCED2L,0x10E122D2742C89BL,0x60DCEE23DD8B0E7L,0x78762B1C2CDED33L,0xEDC0688223FBBD4L,0xAEC25A4621L};
const BIG CURVE_Pybaa= {0x47831F982E50137L,0x857FDDDFCF7A43FL,0x30135945D137B08L,0xCA4E512B64F59F4L,0x7FA238CDCE8A1E2L,0x5F1129857ED85C7L,0xB43DD93B5A95980L,0x88325A2554DC541L,0xA9C46916503FA5AL,0xD209D5A223L};
const BIG CURVE_Pybab= {0x4EEDC58CF90BEE4L,0xA59ED8226CF3A59L,0xFC198CAA72B679DL,0xF47C180D139E3AAL,0xE8C270841F6824L,0x55AB7504FA8342L,0xB16722B589D82E2L,0xD537B90421AD66EL,0x36B7A513D339D5AL,0x7D0D037457L};
const BIG CURVE_Pybba= {0xD41FAEAFEB23986L,0xE884017D9AA62B3L,0x40FA639F53DCCC9L,0xAB8C74B2618B5BBL,0x5AE3A2864F22C1FL,0xE4C819A6DF98F42L,0xC0841B064155F14L,0xD17AF8A006F364FL,0xE65EA25C2D05DFDL,0x896767811BL};
const BIG CURVE_Pybbb= {0x667FFCB732718B6L,0x5AC66E84069C55DL,0xD8C4AB33F748EL,0x333EC7192054173L,0x8E69C31E97E1AD0L,0xEF8ECA9A9533A3FL,0x6BE8E50C87549B6L,0x4F981B5E068F140L,0x9029D393A5C07E8L,0x35E2524FF8L};

#endif

}
