#pragma once

#include <fstream>
#include <queue>

#include "ihandler.h"
#include "bulk.h"

class BaseHandler: public IHandler{

  virtual void handleBulk(Bulk& bulk) = 0;
  
protected:
  std::shared_ptr<std::queue<Bulk>> bulkBuffer;
  
  Bulk extractBulk();
  
public:
  BaseHandler();
  virtual ~BaseHandler() = default;
  BaseHandler(const BaseHandler& other) = delete;
  // BaseHandler operator=(const BaseHandler& other) = delete;
    
  void set(const std::shared_ptr<std::queue<Bulk>>& bulkBuffer) override;  
  void handle() override;
};

#include "baseHandler_impl.h"