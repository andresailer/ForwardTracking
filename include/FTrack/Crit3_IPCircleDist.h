#ifndef Crit2_IPCircleDist_h
#define Crit2_IPCircleDist_h

#include "ICriterion.h"


namespace FTrack{
   
   /** Criterion: ...
    */
   class Crit3_IPCircleDist : public ICriterion{
      
      
      
   public:
      
      Crit3_IPCircleDist ( double distToCircleMax );
      
      virtual bool areCompatible( Segment* parent , Segment* child );
      
      virtual ~Crit3_IPCircleDist(){};
      
      
   private:
      
      double _distToCircleMax;
      
      
   };
   
}













#endif
