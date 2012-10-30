#ifndef STACKED_BAR_GRAPH_H
#define STACKED_BAR_GRAPH_H

#include <osg/Group>
#include <osg/MatrixTransform>
#include <osg/Geode>
#include <osgText/Text>

#include <string>
#include <vector>

class StackedBarGraph
{
    public:
        StackedBarGraph(std::string title, float width, float height);
        virtual ~StackedBarGraph();

        struct SBGData
        {
            std::string name;
            float value;
            std::vector<SBGData*> groups;
            std::vector<SBGData*> flat;
        };

        bool addBar(SBGData * dataRoot, std::vector<std::string> & dataLabels, std::string dataUnits);

        osg::Group * getRoot()
        {
            return _root;
        }

    protected:
        void makeBG();
        osg::Geometry * makeGeometry(int elements);
        void update();
        void updateAxis();
        void updateGraph();

        osgText::Text * makeText(std::string text, osg::Vec4 color);

        std::string _title;
        float _width;
        float _height;

        std::vector<SBGData*> _dataList;
        std::vector<std::vector<std::string> > _dataLabelList;
        std::vector<std::string> _dataUnitsList;

        std::vector<std::string> _currentPath;
        
        osg::ref_ptr<osg::Group> _root;
        osg::ref_ptr<osg::MatrixTransform> _bgScaleMT;
        osg::ref_ptr<osg::Geode> _bgGeode;
        osg::ref_ptr<osg::Geode> _axisGeode;
        osg::ref_ptr<osg::Geode> _graphGeode;

        std::vector<osg::ref_ptr<osg::Geometry> > _geometryList;
        std::vector<osg::ref_ptr<osg::Geometry> > _connectionGeometryList;
        osg::ref_ptr<osg::Geometry> _lineGeometry;
        osg::ref_ptr<osg::DrawArrays> _linePrimitive;

        osg::ref_ptr<osgText::Font> _font;

        float _leftPaddingMult, _rightPaddingMult, _topPaddingMult, _bottomPaddingMult;
        float _barToConnectorRatio;

        float _topTitleMult,_topLevelMult,_topCatHeaderMult;
};

#endif
