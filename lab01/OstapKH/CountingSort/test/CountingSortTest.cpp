//
// Created by Ostap Kilbasovych on 15.03.2022.
//

#include <CountingSorting.h>
#include "gtest/gtest.h"

TEST(CountingSortTestSuite, RandomArray) {

    int arr1[15] = {812, 516, 693, 43, 550, 231, 387, 522, 610, 158, 976, 208, 489, 1, 955};
    int arr2[15] = {94, 256, 34, 650, 787, 536, 337, 155, 228, 485, 973, 45, 794, 616, 454};
    int arr3[15] = {650, 988, 440, 637, 458, 363, 535, 250, 374, 319, 342, 470, 836, 892, 995};
    int arr4[15] = {543, 77, 554, 930, 773, 259, 463, 817, 394, 342, 458, 307, 498, 270, 55};
    int arr5[15] = {280, 734, 30, 523, 810, 325, 849, 205, 767, 990, 619, 883, 913, 984, 517};

    countSort(arr1, 15);
    std::string arr1Str = arrayToString(arr1, 15);

    countSort(arr2, 15);
    std::string arr2Str = arrayToString(arr2, 15);

    countSort(arr3, 15);
    std::string arr3Str = arrayToString(arr3, 15);

    countSort(arr4, 15);
    std::string arr4Str = arrayToString(arr4, 15);

    countSort(arr5, 15);
    std::string arr5Str = arrayToString(arr5, 15);

    EXPECT_EQ(arr1Str, "1 43 158 208 231 387 489 516 522 550 610 693 812 955 976 ");
    EXPECT_EQ(arr2Str, "34 45 94 155 228 256 337 454 485 536 616 650 787 794 973 ");
    EXPECT_EQ(arr3Str, "250 319 342 363 374 440 458 470 535 637 650 836 892 988 995 ");
    EXPECT_EQ(arr4Str, "55 77 259 270 307 342 394 458 463 498 543 554 773 817 930 ");
    EXPECT_EQ(arr5Str, "30 205 280 325 517 523 619 734 767 810 849 883 913 984 990 ");

}


TEST(CountingSortTestSuite, SorteredArray) {

    int arr1[15] = {271, 278, 309, 332, 375, 407, 574, 576, 619, 734, 739, 782, 785, 923, 992};
    int arr2[15] = {69, 121, 136, 227, 229, 319, 368, 417, 578, 588, 637, 649, 858, 860, 942};
    int arr3[15] = {29, 68, 167, 204, 492, 597, 620, 633, 712, 742, 779, 810, 827, 863, 899};
    int arr4[15] = {107, 125, 158, 324, 351, 432, 439, 505, 541, 547, 588, 684, 779, 815, 900};
    int arr5[15] = {120, 156, 171, 210, 334, 341, 370, 707, 723, 752, 790, 802, 896, 908, 914};

    countSort(arr1, 15);
    std::string arr1Str = arrayToString(arr1, 15);

    countSort(arr2, 15);
    std::string arr2Str = arrayToString(arr2, 15);

    countSort(arr3, 15);
    std::string arr3Str = arrayToString(arr3, 15);

    countSort(arr4, 15);
    std::string arr4Str = arrayToString(arr4, 15);

    countSort(arr5, 15);
    std::string arr5Str = arrayToString(arr5, 15);

    EXPECT_EQ(arr1Str, "271 278 309 332 375 407 574 576 619 734 739 782 785 923 992 ");
    EXPECT_EQ(arr2Str, "69 121 136 227 229 319 368 417 578 588 637 649 858 860 942 ");
    EXPECT_EQ(arr3Str, "29 68 167 204 492 597 620 633 712 742 779 810 827 863 899 ");
    EXPECT_EQ(arr4Str, "107 125 158 324 351 432 439 505 541 547 588 684 779 815 900 ");
    EXPECT_EQ(arr5Str, "120 156 171 210 334 341 370 707 723 752 790 802 896 908 914 ");

}

TEST(CountingSortTestSuite, ReversedArray) {

    int arr1[15] = {99, 98, 97, 95, 91, 85, 75, 37, 33, 21, 16, 12, 12, 9, 5};
    int arr2[15] = {494, 491, 477, 476, 470, 469, 428, 394, 309, 308, 260, 216, 111, 107, 104};
    int arr3[15] = {464, 447, 444, 355, 350, 331, 324, 291, 284, 276, 214, 192, 106, 93, 11};
    int arr4[15] = {840, 823, 812, 750, 732, 700, 650, 633, 403, 402, 173, 155, 106, 61, 6};
    int arr5[15] = {23389, 22980, 22423, 21996, 21747, 21372, 21269, 20862, 14475, 9890, 9171, 6094, 2456, 1052, 1021};

    countSort(arr1, 15);
    std::string arr1Str = arrayToString(arr1, 15);

    countSort(arr2, 15);
    std::string arr2Str = arrayToString(arr2, 15);

    countSort(arr3, 15);
    std::string arr3Str = arrayToString(arr3, 15);

    countSort(arr4, 15);
    std::string arr4Str = arrayToString(arr4, 15);

    countSort(arr5, 15);
    std::string arr5Str = arrayToString(arr5, 15);

    EXPECT_EQ(arr1Str, "5 9 12 12 16 21 33 37 75 85 91 95 97 98 99 ");
    EXPECT_EQ(arr2Str, "104 107 111 216 260 308 309 394 428 469 470 476 477 491 494 ");
    EXPECT_EQ(arr3Str, "11 93 106 192 214 276 284 291 324 331 350 355 444 447 464 ");
    EXPECT_EQ(arr4Str, "6 61 106 155 173 402 403 633 650 700 732 750 812 823 840 ");
    EXPECT_EQ(arr5Str, "1021 1052 2456 6094 9171 9890 14475 20862 21269 21372 21747 21996 22423 22980 23389 ");

}