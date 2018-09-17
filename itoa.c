

#include "itoa.h"

char* itoa(char* s, uint8_t num, uint8_t radix){
    switch(radix){
        case 16 :
            for(uint8_t i = 0; i < 2; i++){
                uint8_t halfside = num >> 4;
                if(halfside < 10) *s++ = (char)(0x30 + halfside);
                else *s++ = (char)(0x41 + halfside - 10);
            }
            *s = 0x00;
            break;
            
        case 10 :
            for(uint8_t i = 0; i < 2; i++){
                uint8_t div = i == 0 ? 100 : 10;
                uint8_t quotient = num / div;
                *s++ = (char)(0x30 + quotient);
                num = num - quotient * div;
            }
            *s++ = (char)(0x30 + num);
            *s = 0x00;
            break;
        case 2:
            for(uint8_t i = 0; i < 8; i++){
                uint8_t mask = 0;
                switch(i){
                    case 0 : mask = 0b10000000; break;
                    case 1 : mask = 0b01000000; break;
                    case 2 : mask = 0b00100000; break;
                    case 3 : mask = 0b00010000; break;
                    case 4 : mask = 0b00001000; break;
                    case 5 : mask = 0b00000100; break;
                    case 6 : mask = 0b00000010; break;
                    case 7 : mask = 0b00000001; break;
                }
                *s++ = (num & mask) != 0 ? (char)0x31 : (char)0x30;
            }
            *s = 0x00;
            break;
        default:
            *s = 0;
            break;
    }
    return s;
}
//
//char* itoa(char* s, int8_t num, uint8_t radix){
//    switch(radix){
//        case 16 :
//            for(uint8_t i = 0; i < 2; i++){
//                uint8_t halfside = num >> 4;
//                if(halfside < 10) &s++ = (char)(0x30 + halfside);
//                else *s++ = (char)(0x41 + halfside - 10);
//            }
//            *s = 0x00;
//            break;
//            
//        case 10 :
//            if(num < 0) {
//                *s++ = '-';
//                num = num * -1;
//            }
//            for(uint8_t i = 0; i < 2; i++){
//                uint8_t div = i == 0 ? 100 : 10;
//                *s++ = (char)(0x30 + (num / div));
//            }
//            *s++ = (char)(0x30 + (num % div));
//            *s = 0x00;
//            break;
//        case 2:
//            for(uint8_t i = 0; i < 8; i++){
//                uint8_t mask = 0;
//                switch(i){
//                    case 0 : mask = 0b10000000; break;
//                    case 1 : mask = 0b01000000; break;
//                    case 2 : mask = 0b00100000; break;
//                    case 3 : mask = 0b00010000; break;
//                    case 4 : mask = 0b00001000; break;
//                    case 5 : mask = 0b00000100; break;
//                    case 6 : mask = 0b00000010; break;
//                    case 7 : mask = 0b00000001; break;
//                }
//                *s++ = num & mask != 0 ? (char)0x31 : (char)0x30;
//            }
//            *s = 0x00;
//            break;
//        default:
//            *s = 0;
//            break;
//    }
//    return s;
//}
