#ifndef CONTROLS_HPP
#define CONTROLS_HPP

#include <glm/glm.hpp>

glm::mat4 getTransformedVector();
void computeScalingMatrix();
void computeTranslationMatrices();

void computeMatricesFromInputs();
glm::mat4 getViewMatrix();
glm::mat4 getProjectionMatrix();

#endif
