#pragma once
#include "FileSystemElement.hpp"

class File : public FileSystemElement {
    private:
        std::string content;
    public:
        File(std::string filename) : FileSystemElement(filename) {  }
        File(std::string filename, std::string fileContent) : FileSystemElement(filename) {
            content = fileContent;
        }

        static void registerUsertype(sol::state& lua) {
            sol::usertype<File> fileType = lua.new_usertype<File>("File",
                sol::constructors<File(std::string), File(std::string, std::string)>(),
                sol::base_classes, sol::bases<FileSystemElement>());

            fileType.set_function("getName", &File::getName);
            fileType.set_function("getType", &File::getType);
            fileType.set_function("setParent", &File::setParent);
            fileType.set_function("getContent", &File::getContent);
            fileType.set_function("append", &File::append);

            fileType.set_function("delete", &File::destroy);
        }

        FileSystemType getType() {
            return FileSystemType::File;
        }

        std::string getContent() {
            return content;
        }

        void append(std::string text) {
            content += text;
        }
};
