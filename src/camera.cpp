#include "camera.h"
namespace TREngine{
    void Camera::updateCameraVectors(){
        // calculate the new Front vector
        glm::vec3 front;
        front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
        front.y = sin(glm::radians(Pitch));
        front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
        Front = glm::normalize(front);
        // also re-calculate the Right and Up vector
        Right = glm::normalize(glm::cross(Front, WorldUp));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
        Up    = glm::normalize(glm::cross(Right, Front));
    }
    void Camera::updata(GLFWwindow *window,float deltaTime){
        float velocity = MovementSpeed * deltaTime;
        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
            Position += Front * velocity;
        }
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
            Position -= Front * velocity;
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
            Position -= Right * velocity;
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
            Position += Right * velocity;

    }
    void Camera::setPathSetYaw(float path,float yaw){
       Pitch = path;
       Yaw = yaw;
       updateCameraVectors();
    }
    void Camera::SetZoom(float zoom){
        Zoom = zoom;
        if (Zoom < 1.0f)
            Zoom = 1.0f;
        if (Zoom > 45.0f)
            Zoom = 45.0f;
    }
    void Camera::updatabyGUI(const std::string cmd,float deltaTime){
        float velocity = MovementSpeed * deltaTime;
        static float position_y = 0;
        if (cmd == "FORWARD")
            Position += Front * velocity;
        if (cmd == "BACKWARD")
            Position -= Front * velocity;
        if (cmd == "LEFT")
            Position -= Right * velocity;
        if (cmd == "RIGHT")
            Position += Right * velocity;
        if(cmd =="UP"){
           position_y += velocity;
        }
        if(cmd =="DOWN"){
            position_y -= velocity;
        }
        Position.y=position_y;
    }
    void Camera::ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true)
    {
        xoffset *= MouseSensitivity;
        yoffset *= MouseSensitivity;

        Yaw   += xoffset;
        Pitch += yoffset;

        // make sure that when pitch is out of bounds, screen doesn't get flipped
        if (constrainPitch)
        {
            if (Pitch > 89.0f)
                Pitch = 89.0f;
            if (Pitch < -89.0f)
                Pitch = -89.0f;
        }

        // update Front, Right and Up Vectors using the updated Euler angles
        updateCameraVectors();
    }

    // processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
    void Camera::ProcessMouseScroll(float yoffset)
    {
        Zoom -= (float)yoffset;
        if (Zoom < 1.0f)
            Zoom = 1.0f;
        if (Zoom > 45.0f)
            Zoom = 45.0f;
    }



}