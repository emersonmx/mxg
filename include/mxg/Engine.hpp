#ifndef MXG_ENGINE_HPP_
#define MXG_ENGINE_HPP_

#include <string>
#include <cstdlib>

namespace mxg {

bool isRunning() const;

void loadSettingsFromFile(const std::string& filename);

int run();
void exit(const int exitCode = EXIT_SUCCESS);

} /* namespace mxg */
#endif /* MXG_ENGINE_HPP_ */
