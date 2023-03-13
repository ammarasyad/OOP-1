#ifndef IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_RANDOM_HPP
#define IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_RANDOM_HPP

// x86 RDRAND Intrinsic, pls pake ini aja ty (buat manual g++ users ini dicompile pake flag -mrdrnd)
inline unsigned int getRandom() {
    unsigned int result;
    __builtin_ia32_rdrand32_step(&result);
    return result % 13 + 1; // Hasil bakal 1-13
}

#endif
