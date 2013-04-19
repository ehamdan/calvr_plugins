#ifndef FP_LAYOUT_INTERFACES_H
#define FP_LAYOUT_INTERFACES_H

#include <cvrKernel/TiledWallSceneObject.h>

class LayoutTypeObject : public cvr::TiledWallSceneObject
{
    public:
        LayoutTypeObject(std::string name, bool navigation, bool movable, bool clip, bool contextMenu, bool showBounds=false) : TiledWallSceneObject(name,navigation,movable,clip,contextMenu,showBounds)
        {
        }
        virtual ~LayoutTypeObject()
        {
        }

        virtual void setGraphSize(float width, float height) = 0;
        virtual bool getLayoutDoesDelete()
        {
            return false;
        }
        virtual void perFrame()
        {
        }
        virtual void setGLScale(float scale)
        {
        }
        virtual void setBarVisible(bool vis)
        {
        }
        virtual float getBarPosition()
        {
            return 0.0;
        }
        virtual void setBarPosition(float pos)
        {
        }
        virtual  bool getGraphSpacePoint(const osg::Matrix & mat, osg::Vec3 & point)
        {
            return false;
        }
        virtual void dumpState(std::ostream & out)
        {
            out << "UNKNOWN" << std::endl;
        }
        virtual bool loadState(std::istream & in)
        {
            return true;
        }
};

class TimeRangeObject
{
    public:
        virtual void setGraphDisplayRange(time_t start, time_t end) = 0;
        virtual void getGraphDisplayRange(time_t & start, time_t & end) = 0;
        virtual void resetGraphDisplayRange() = 0;
        virtual time_t getMaxTimestamp() = 0;
        virtual time_t getMinTimestamp() = 0;
};

class ValueRangeObject
{
    public:
        virtual float getGraphMaxValue() = 0;
        virtual float getGraphMinValue() = 0;

        virtual float getGraphDisplayRangeMax() = 0;
        virtual float getGraphDisplayRangeMin() = 0;

        virtual void setGraphDisplayRange(float min, float max) = 0;
        virtual void resetGraphDisplayRange() = 0;
};

class LogValueRangeObject
{
    public:
        virtual float getGraphXMaxValue() = 0;
        virtual float getGraphXMinValue() = 0;
        virtual float getGraphZMaxValue() = 0;
        virtual float getGraphZMinValue() = 0;

        virtual float getGraphXDisplayRangeMax() = 0;
        virtual float getGraphXDisplayRangeMin() = 0;
        virtual float getGraphZDisplayRangeMax() = 0;
        virtual float getGraphZDisplayRangeMin() = 0;

        virtual void setGraphXDisplayRange(float min, float max) = 0;
        virtual void setGraphZDisplayRange(float min, float max) = 0;
        virtual void resetGraphDisplayRange() = 0;
};

class MicrobeSelectObject
{
    public:
        virtual void selectMicrobes(std::string & group, std::vector<std::string> & keys) = 0;
};

class PatientSelectObject
{
    public:
        virtual void selectPatients(std::vector<std::string> & patients) = 0;
};
#endif
