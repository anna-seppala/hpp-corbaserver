/*
  Research carried out within the scope of the Associated International Laboratory: Joint Japanese-French Robotics Laboratory (JRL)

  Developed by Florent Lamiraux (LAAS-CNRS)

*/

#ifndef HPPCI_PROBLEM_H
#define HPPCI_PROBLEM_H

#include <vector>

#undef PACKAGE_BUGREPORT
#undef PACKAGE_NAME
#undef PACKAGE_STRING
#undef PACKAGE_TARNAME
#undef PACKAGE_VERSION
#include "hppciProblemServer.hh"

class ChppciServer;
/**
 * \brief Implementation of corba interface ChppciProblem.
 */
class ChppciProblem_impl : public virtual POA_ChppciProblem {
public:
  ChppciProblem_impl(ChppciServer* inHppciServer);
  /// \brief Comment in interface ChppciPRoblem::setSteeringMethod.
  virtual CORBA::Short setSteeringMethod(CORBA::Short inProblemId, 
					 const char* inSteeringMethod, CORBA::Boolean inOriented);

  /// \brief Comment in interface ChppciPRoblem::setRoadmapbuilder
  virtual CORBA::Short setRoadmapbuilder(CORBA::Short inProblemId, const char* inRoadmapBuilder);

  /// \brief Comment in interface ChppciPRoblem::setPathOptimizer
  virtual CORBA::Short setPathOptimizer(CORBA::Short inProblemId, const char* inPathOptimizer);

  /// \brief Comment in interface ChppciPRoblem::setInitialConfig
  virtual CORBA::Short setInitialConfig(CORBA::Short inProblemId, const dofSeq& dofArray);

  /// \brief Comment in interface ChppciPRoblem::setGoalConfig
  virtual CORBA::Short setGoalConfig(CORBA::Short inProblemId, const dofSeq& dofArray);

  /// \brief Comment in interface ChppciPRoblem::initializeProblem
  virtual CORBA::Short initializeProblem();

  /// \brief Comment in interface ChppciPRoblem::solveOneProblem
  virtual CORBA::Short solveOneProblem(CORBA::Short inProblemId, CORBA::Short& inLastPathId, CORBA::Double& pathLength) ;

  /// \brief Comment in interface ChppciPRoblem::solve
  virtual CORBA::Short solve();

  /// \brief Comment in interface ChppciPRoblem::optimizePath
  virtual CORBA::Short optimizePath(CORBA::Short inProblemId, CORBA::Short inPathId);

  /// \brief Comment in interface ChppciPRoblem::configAtDistance
  virtual dofSeq* configAtDistance(CORBA::Short inProblemId, CORBA::Short pathId, CORBA::Double pathLength, CORBA::Double atDistance) ;

  /// \brief Comment in interface ChppciPRoblem::setObstacleTolerance
  virtual CORBA::Short setObstacleTolerance(CORBA::Short inProblemId, CORBA::Double tolerance)
    throw(CORBA::SystemException);

private:
  /// \brief Pointer to the ChppciServer owning this object
  ChppciServer* attHppciServer;
  /// \brief Pointer to hppPlanner object of hppciServer.
  /// Instantiated at construction.
  ChppPlanner *attHppPlanner;
};  


#endif