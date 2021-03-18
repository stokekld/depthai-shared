#pragma once

#include <vector>
#include "depthai-shared/common/CameraBoardSocket.hpp"
#include "depthai-shared/common/Point3f.hpp"

struct Extrinsics {
    std::vector<std::vector<float>> rotationMatrix;
    // (x, y, z) pose of destCameraSocket w.r.t currentCameraSocket obtained through calibration
    Point3f translation;
    // (x, y, z) pose of destCameraSocket w.r.t currentCameraSocket measured through CAD design
    Point3f measuredTranslation;
    CameraBoardSocket toCameraSocket;
    /** FIXME(sachin): Why does fromCameraSocket needs to be vector? fromCameraSockets 
     * is not part of eeprom write. it just enables in linking between cameras after eeprom read.
     */
    std::vector<CameraBoardSocket> fromCameraSockets;
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Extrinsics, rotationMatrix, translation, measuredTranslation, toCameraSocket, fromCameraSockets);
};