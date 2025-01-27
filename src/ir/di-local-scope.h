#ifndef LLVM_NODE_DI_LOCAL_SCOPE_H
#define LLVM_NODE_DI_LOCAL_SCOPE_H

#include <nan.h>
#include <llvm/IR/DebugInfoMetadata.h>
#include "../util/from-value-mixin.h"
#include "di-scope.h"

class DILocalScopeWrapper: public DIScopeWrapper, public FromValueMixin<DILocalScopeWrapper> {
    public:
        static NAN_MODULE_INIT(Init);
        llvm::DILocalScope *getDILocalScope();
        static v8::Local<v8::Object> of(llvm::DILocalScope *);
        static bool isInstance(v8::Local<v8::Value>);
        using FromValueMixin<DILocalScopeWrapper>::FromValue;

        DILocalScopeWrapper(llvm::DILocalScope *);
    
    private:
        llvm::DILocalScope *diLocalScope;

        static NAN_METHOD(New);
        static NAN_METHOD(getSubprogram);
    protected:
        static Nan::Persistent<v8::FunctionTemplate> &diLocalScopeTemplate();
};

#endif //LLVM_NODE_DI_LOCAL_SCOPE_H