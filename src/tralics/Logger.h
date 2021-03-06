#pragma once
#include "Buffer.h"
#include <fstream>
#include <memory>
#include <spdlog/spdlog.h>

inline Buffer        buffer_for_log2; // Only used out_single_char and finish_seq
inline std::ofstream log_file;        // the stream to which we print

/** The remains of the Logger class from the previous tralics version.
 * Now it only does bookkeeping of the ostreams previously used.
 */

struct Logger {
    static void log_dump(const std::string &s); ///< Log argument surrounded by braces
    static void log_finish();                   // \todo This belongs in the destructor but spdlog could die first

    static void out_single_char(char32_t c) { buffer_for_log2 << c; }

    static void finish_seq() {
        if (!buffer_for_log2.empty()) {
            spdlog::trace("Character sequence: {}.", buffer_for_log2.convert_to_log_encoding());
            buffer_for_log2.clear();
        }
    }
};

// By default, send things to the log file. In Logger, this defaulted to
// both console and file, those are all log_and_tty in the code for
// now. \todo So replace `the_log <<` with spdlog::trace, and `log_and_tty <<`
// with spdlog::info.
template <typename T> auto operator<<(Logger &L, const T &s) -> Logger & {
    log_file << s;
    return L;
}

inline Logger  log_and_tty;
inline Logger &the_log = log_and_tty;
