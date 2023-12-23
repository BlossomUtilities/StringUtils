#pragma once

#include <cctype>
#include <stdexcept>
#include <cstring>

namespace Blossom::Utils {
    /**
     * @brief Makes working with strings easier.
     * 
     * @class String
     */
    class String {
        public:
            /**
             * @brief Replaces all occurrences of the specified `from` value with the `to` value within the given string.
             *
             * @param inputString The string in which replacements will be made.
             * @param from The value to be replaced.
             * @param to The value to replace with.
             * @return A new string with all 'from' occurrences replaced by 'to'.
             *
             * @throw std::out_of_range If the key does not include the value of the `to` argument.
             */
            static std::string replace(const std::string& inputString, const std::string& from, const std::string& to) {
                std::string result = inputString;
                size_t startPos = result.find(from);

                if (startPos != std::string::npos) {
                    result.replace(startPos, from.length(), to);
                } else {
                    throw std::out_of_range("String::replace: 'from' not found in the input string.");
                }

                return result;
            }

            /**
             * @brief Splits the given string based on the specified delimiter.
             *
             * @param inputString The string to be split.
             * @param delimiter The character to use as a delimiter.
             * @return The substring before the first occurrence of the delimiter.
             */
            static std::string split(const std::string& inputString, char delimiter) {
                size_t delimiterPos = inputString.find(delimiter);
                return inputString.substr(0, delimiterPos);
            }

            /**
             * @brief Capitalizes the first letter of the input string.
             *
             * @param inputString The string to capitalize.
             * @return A new string with the first letter capitalized.
             */
            static std::string capitalizeFirstLetter(const std::string& inputString) {
                if (inputString.empty()) {
                    return inputString;
                }

                std::string result = inputString;
                result[0] = std::toupper(result[0]);

                return result;
            }

            /**
             * @brief Creates a duplicate of a C-style string.
             *
             * @param srcStr A pointer to the source C-style string to be duplicated.
             * @return A new dynamically allocated C-style string containing a copy of the source string.
             * @note You'll need to delete the string using `delete[]`.
             */
            static char* duplicateChar(const char* srcStr) noexcept {
                if (srcStr == nullptr) {
                    return nullptr;
                }

                size_t length = std::strlen(srcStr);
                char* newStr = new char[length + 1];

                strcpy(newStr, srcStr);

                return newStr;
            }

            /**
             * @brief Creates a duplicate of a C++ std::string.
             *
             * @param srcString A reference to the source std::string to be duplicated.
             * @return A new dynamically allocated C-style string containing a copy of the source string.
             * @note You'll need to delete the string using `delete[]`.
             */
            static char* duplicateString(const std::string& srcString) {
                return duplicateChar(srcString.c_str());
            }
    };
}
