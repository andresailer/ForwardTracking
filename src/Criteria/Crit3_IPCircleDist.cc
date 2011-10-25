#include "Crit3_IPCircleDist.h"

#include "SimpleCircle.h"
#include <cmath>

using namespace FTrack;


Crit3_IPCircleDist::Crit3_IPCircleDist( float distToCircleMin , float distToCircleMax ){
   
   _distToCircleMax  = distToCircleMax;
   _distToCircleMin  = distToCircleMin;
   
   _saveValues = false;
   
}



bool Crit3_IPCircleDist::areCompatible( Segment* parent , Segment* child )throw( BadSegmentLength ){
   

   
   
   if (( parent->getAutHits().size() == 2 )&&( child->getAutHits().size() == 2 )){ //a criterion for 2-segments


      AutHit* a = parent->getAutHits()[0];
      AutHit* b = parent->getAutHits()[1];
      AutHit* c = child-> getAutHits()[1];
      
      float ax = a->getX();
      float ay = a->getY();
     
      float bx = b->getX();
      float by = b->getY();
      
      float cx = c->getX();
      float cy = c->getY();


      try{

         SimpleCircle circle ( ax , ay , bx , by , cx , cy );
         
         double x = circle.getCenterX();
         double y = circle.getCenterY();
         double R = circle.getRadius();
         
         double circleDistToIP = fabs( R - sqrt (x*x+y*y) );
         
         if (_saveValues) _map_name_value["IPCircleDist_IPCircleDist"] =  circleDistToIP;
               
         if ( circleDistToIP  > _distToCircleMax ) return false;
         if ( circleDistToIP  < _distToCircleMin ) return false;

      }
      catch ( InvalidParameter ){
         
         
         if (_saveValues) _map_name_value["IPCircleDist_IPCircleDist"] =  0.;
         
      }



   }
   else{
      
      std::string s = "Crit3_IPCircleDist::This criterion needs 2 segments with 2 hits each, passed was a "
      +  intToString( parent->getAutHits().size() ) + " hit segment (parent) and a "
      +  intToString( child->getAutHits().size() ) + " hit segment (child).";
      
      
      throw BadSegmentLength( s );
      
      
   }
   
   
   return true;
   
   
}