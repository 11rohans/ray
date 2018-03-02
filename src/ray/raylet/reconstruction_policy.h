#ifndef RECONSTRUCTION_POLICY_H
#define RECONSTRUCTION_POLICY_H

#include <functional>

#include "ray/id.h"

namespace ray {

// TODO(swang): Use std::function instead of boost.

class ReconstructionPolicy {
 public:
  // TODO(swang): This requires at minimum references to the Raylet's lineage
  // cache and GCS client.
  ReconstructionPolicy() {}
  // If this object requires reconstruction, the task reconstruction
  // handler will be called for the tasks that need to be re-executed.
  void CheckObjectReconstruction(const ObjectID &object);
  // Register a handler to call if a task needs to be reconstructed.
  void RegisterTaskReconstructionHandler(std::function<void(const TaskID&)> reconstruction_handler);
 private:
};

} // end namespace ray

#endif  // RECONSTRUCTION_POLICY_CC