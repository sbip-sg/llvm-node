#ifndef LLVM_NODE_DI_FILE_H
#define LLVM_NODE_DI_FILE_H

#include <nan.h>
#include <llvm/IR/DebugInfoMetadata.h>
#include "../util/from-value-mixin.h"

class DIFileWrapper: public Nan::ObjectWrap, public FromValueMixin<DIFileWrapper> {
    public:
        static NAN_MODULE_INIT(Init);
        static v8::Local<v8::Object> of(llvm::DIFile *);
        llvm::DIFile *getDIFile();
        static bool isInstance(v8::Local<v8::Value>);

        DIFileWrapper(llvm::DIFile *);
    
    private:
        llvm::DIFile *diFile;

        static NAN_METHOD(New);

        static Nan::Persistent<v8::FunctionTemplate> &diFileTemplate();
};

#endif //LLVM_NODE_DI_FILE_H