#ifndef _CALLBACKS_H_
#define _CALLBACKS_H_

#include <functional>
#include <memory>
#include "Timestamp.h"
#include "Buffer.h"

typedef std::function<void()> TimerCallback;

// The only one that uses shared_ptr
class TcpConnection;
typedef std::shared_ptr<TcpConnection> TcpConnectionPtr;

typedef std::function<void (const TcpConnectionPtr&)> ConnectionCallback;
// implementation in TcpConnetcion.cc in muduo project
void defaultConnectionCallback(const TcpConnectionPtr& conn);

typedef std::function<void (const TcpConnectionPtr&, Buffer*, int)> MessageCallback;
void defaultMessageCallback(const TcpConnectionPtr& conn, Buffer*, int n);


typedef std::function<void (const TcpConnectionPtr&)> CloseCallback;
typedef std::function<void (const TcpConnectionPtr&)> WriteCompleteCallback;
typedef std::function<void (const TcpConnectionPtr&, size_t)> HighWaterMarkCallback;
// get_pointer as it be named
template<class T>
T* get_pointer(T* p){
    return p;
}

template<class T>
T* get_pointer(std::unique_ptr<T> const& p){
    return p.get();
}

template<class T>
T* get_pointer(std::shared_ptr<T> const& p){
    return p.get();
}

#endif
