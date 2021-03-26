#ifndef EMPGE_OLCPEX_TAS_H
#define EMPGE_OLCPEX_TAS_H

#include "olcPixelGameEngine.h"

#include <vector>
#include <fstream>

namespace olc
{
    namespace tas
    {
        class InputController : public olc::PGEX
        {
        private:
        protected:
            void OnBeforeUserCreate() final;
            void OnAfterUserCreate() final;
            void OnBeforeUserUpdate(float& fElapsedTime) final;
            void OnAfterUserUpdate(float fElapsedTime) final;
        };
    }  // namespace tas
}  // namespace olc

namespace olc
{
    namespace tas
    {
        void InputController::OnBeforeUserCreate()
        {
            PGEX::OnBeforeUserCreate();
        }
        void InputController::OnAfterUserCreate()
        {
            PGEX::OnAfterUserCreate();
        }
        void InputController::OnBeforeUserUpdate(float& fElapsedTime)
        {
            PGEX::OnBeforeUserUpdate(fElapsedTime);
        }
        void InputController::OnAfterUserUpdate(float fElapsedTime)
        {
            PGEX::OnAfterUserUpdate(fElapsedTime);
        }
    }  // namespace tas
}  // namespace olc

#endif  // EMPGE_OLCPEX_TAS_H
